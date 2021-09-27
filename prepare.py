#!/usr/bin/python3




import signal, sys
def signal_handler(sig, frame):
    print('You pressed Ctrl+C!')
    sys.exit(0)
signal.signal(signal.SIGINT, signal_handler)




from abc import ABC, abstractmethod
from datetime import datetime

'''
classes from
https://github.com/lukewarlow/PythonConsoleMenu
'''

class OperationError(Exception):
    def __init__(self):
        super().__init__("Invalid operation")


class AbstractMenu(ABC):
    def __init__(self, title: str):
        self.title = title
        self.menu_items = []
        self.initialise()

    @abstractmethod
    def initialise(self):
        pass

    def update_menu_items(self):
        pass

    def item_text(self, item: 'MenuItem'):
        return "%s" % item.description

    def item_line(self, index: int, item: 'MenuItem'):
        return "%s. %s" % (index, self.item_text(item))

    def display(self):
        repeat: bool = True
        while repeat:
            self.update_menu_items()
            print()
            print(self.title)
            for i in range(0, len(self.menu_items)):
                if self.menu_items[i].isVisible:
                    print(self.item_line(i, self.menu_items[i]))

            inp = input("Select Option: ")
            try:
                menu_item = self.menu_items[int(inp)]
                if menu_item.isVisible:
                    repeat = menu_item.run()
                else:
                    raise OperationError()
            except ValueError:
                print("Invalid option, you need to enter a number.", inp)
                repeat = True
            except IndexError:
                print("Invalid option. Option {0} doesn't exist.".format(inp))
                repeat = True
            except OperationError:
                print("Invalid option. Option at {0} is hidden.".format(inp))
                repeat = True

    def add_menu_item(self, menu_item: 'MenuItem'):
        if not self.menu_items.__contains__(menu_item):
            self.menu_items.append(menu_item)
        else:
            raise ValueError("Menu item with id {0} already exists!.".format(menu_item.id))

    def add_hidden_menu_item(self, menu_item: 'MenuItem'):
        self.add_menu_item(menu_item.hide())

    def show_menu_item(self, item_id: int):
        try:
            menu_item = MenuItem(item_id)
            index = self.menu_items.index(menu_item)
            self.menu_items[index].show()
        except ValueError:
            print("Error showing menu item. Menu item with ID {0} hasn't been added to this menu.".format(item_id))

    def hide_menu_item(self, item_id: int):
        try:
            menu_item = MenuItem(item_id)
            index = self.menu_items.index(menu_item)
            self.menu_items[index].hide()
        except ValueError:
            print("Error hiding menu item. Menu item with ID {0} hasn't been added to this menu.".format(item_id))


class MenuItem:
    def __init__(self, id: int, description: str = "", action: callable(None) = None, menu: AbstractMenu = None, args: list = []):
        self.id: int = id
        self.description: str = description
        self.action = action
        self.menu: AbstractMenu = menu
        self.isExitOption: bool = False
        self.isVisible: bool = True
        self.args: list = args

    def hide(self) -> 'MenuItem':
        self.isVisible = False
        return self

    def show(self) -> 'MenuItem':
        self.isVisible = True
        return self

    def set_as_exit_option(self) -> 'MenuItem':
        self.isExitOption = True
        return self

    def run(self) -> bool:
        if self.action is not None:
            self.action(*self.args)
        elif self.menu is not None:
            self.menu.display()

        return not self.isExitOption

    def __eq__(self, other):
        if isinstance(other, self.__class__):
            return self.id == other.id
        else:
            return False

    def __ne__(self, other):
        return not self.__eq__(other)






import tarfile, io, os



try:
    import requests
    pass
except ImportError:
    print('Vous devez installer le package requests pour faire fonctionner ce programme:\n')
    print('   pip3 install requests')
    exit(1)



import sys

if '--update' in sys.argv:
    print("Updating 📑")
    r = requests.get('https://git.unistra.fr/-/snippets/132/raw')
    with open(__file__, 'w') as f:
        f.write(r.text)
        print("Done 🎉")

    exit(0)

code = ''
for i in range(len(sys.argv) - 1):
    if sys.argv[i] == '--code':
        code = '?code='+sys.argv[i+1]




r = requests.get('https://api.tps.bramas.fr/api/problems'+code)

problems = list(sorted(r.json(), key=lambda p: p['starting_date']))


problemsGrouped = {}

for p in problems:
    s = p['name'].split('/')
    if s[0] not in problemsGrouped:
        problemsGrouped[s[0]] = []
    problemsGrouped[s[0]].append(p)



def download(path, url):
    print('Téléchargement de '+path+' ...', end='')
    z_r = requests.get(url+code, stream=True)
    t = tarfile.open(fileobj=z_r.raw, mode='r:gz')

    if os.path.exists(path):
        print('Attention, le dossier existe, certains fichiers risquent d\être remplacés.\n')
        print('Voulez vous écraser les fichiers existant (sans risque si vous avez commit vos modifications)\n(y/n)')
        if input() != 'y':
            print('Annulé!!')
            input('appuyer sur Entrée pour continuer')
            return

    t.extractall(path)
    print('OK\n')
    input('appuyer sur Entrée pour continuer')


def remainingTime(dt):
    if not dt: return ''

    d, t = dt.split('.')[0].split('T')
    d = [int(x) for x in d.split('-')]
    t = [int(x) for x in t.split(':')]
    diff = datetime(d[0], d[1], d[2], t[0], t[1], t[2]) - datetime.utcnow()
    if diff.total_seconds() < 0:
        return 'Passé'
    return str(diff).split('.')[0]


class GroupMenuSubMenu(AbstractMenu):
    group = None
    _hideExisting = True
    _toggleExistingVisibilityItem = None

    def __init__(self, group):
        self.group = group
        super().__init__("Liste "+str(group))

    
    def toggleExistingVisibility(self):
        if self._hideExisting:
            self.showExisting()
        else:
            self.hideExisting()

    def hideExisting(self):
        self._hideExisting = True
        self._toggleExistingVisibilityItem.description = "Show existing problems"
        for p in problemsGrouped[self.group]:
            if  os.path.exists(p['name']):
                self.hide_menu_item(p['menu_id'])

    def showExisting(self):
        self._hideExisting = False
        self._toggleExistingVisibilityItem.description = "Hide existing problems"
        for p in problemsGrouped[self.group]:
            self.show_menu_item(p['menu_id'])

    def initialise(self):
        self.add_menu_item(MenuItem(0, "<< Back").set_as_exit_option())
        self._toggleExistingVisibilityItem = MenuItem(1, "", action=self.toggleExistingVisibility)
        self.add_menu_item(self._toggleExistingVisibilityItem)
        idx = 1
        for p in problemsGrouped[self.group]:
            idx += 1
            text = ("*"*p['difficulty']).ljust(6,' ') +' '+p['name']
            if p['deadline']:
                text += ' ('+remainingTime(p['deadline'])+')'
            m = MenuItem(idx, text, lambda: download(p['name'], p['url']))
            self.add_menu_item(m)
            p['menu_id'] = idx

        self.hideExisting()


class GroupMenu(AbstractMenu):
    subMenus = []
    _hideExisting = True
    _toggleExistingVisibilityItem = None

    def __init__(self):
        super().__init__("Welcome to the test menu.")

    def showGroup(self, group):
        if group in self.groupVisible:
            self.groupVisible[group] = False
        self.groupVisible[group] = True
        for p in problemsGrouped[group]:
            self.hide_menu_item(p['menu_id'])
        print('show', group)
    
    def hideExisting(self):
        self._hideExisting = True
        self._toggleExistingVisibilityItem.description = "Show existing problems"
        for m in self.subMenus:
            m.menu.hideExisting()

    def showExisting(self):
        self._hideExisting = False
        self._toggleExistingVisibilityItem.description = "Hide existing problems"
        for m in self.subMenus:
            m.menu.showExisting()

    def toggleExistingVisibility(self):
        if self._hideExisting:
            self.showExisting()
        else:
            self.hideExisting()


    def initialise(self):
        self.add_menu_item(MenuItem(0, "Exit menu").set_as_exit_option())
        self._toggleExistingVisibilityItem = MenuItem(1, "", action=self.toggleExistingVisibility)
        self.add_menu_item(self._toggleExistingVisibilityItem)
        idx = 1
        for group, problems in problemsGrouped.items():

            #if not displayAll and os.path.exists(p['name']) and not self.seeAll:
            #    continue
            

            idx += 1
            m = MenuItem(idx, group, menu=GroupMenuSubMenu(group))
            self.add_menu_item(m)
            self.subMenus.append(m)
            
        self.hideExisting()


class ListMenu(AbstractMenu):
    _hideExisting = True
    _toggleExistingVisibilityItem = None

    def __init__(self):
        super().__init__("Bienvenu dans le gestionnaire de TP")

    def updateVisibility(self):
        if self._hideExisting:
            for p in problems:
                if  os.path.exists(p['name']):
                    self.hide_menu_item(p['menu_id'])
        else:
            for p in problems:
                self.show_menu_item(p['menu_id'])
    
    def hideExisting(self):
        self._hideExisting = True
        self._toggleExistingVisibilityItem.description = \
            "\t        🙉 Montrer les problèmes existants"
        self.updateVisibility()

    def showExisting(self):
        self._hideExisting = False
        self._toggleExistingVisibilityItem.description = \
            "\t        🙈 Cacher les problèmes existants"
        self.updateVisibility()

    def toggleExistingVisibility(self):
        if self._hideExisting:
            self.showExisting()
        else:
            self.hideExisting()

    def selectProblem(self, name, url):
        download(name, url)
        self.updateVisibility()

    def initialise(self):
        self.add_menu_item(MenuItem(0, "\t        ❌ Quitter").set_as_exit_option())
        self._toggleExistingVisibilityItem = MenuItem(1, "", action=self.toggleExistingVisibility)
        self.add_menu_item(self._toggleExistingVisibilityItem)
        
        idx = 1
        for p in problems:
            idx += 1
            text = ("⭐"*p['difficulty']).ljust(6,' ') +'\t'
            rtime = remainingTime(p['deadline'])
            if rtime != '':
                text += '🕓 '
            else:
                text += '   '
            text += p['name']

            if p['deadline']:
                text += ' ('+rtime+')'
            m = MenuItem(idx, text, action=self.selectProblem, args=[p['name'], p['url']])
            self.add_menu_item(m)
            p['menu_id'] = idx
            
        self.hideExisting()



demoMenu = ListMenu()
demoMenu.display()
