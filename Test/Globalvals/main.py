"""Show difference in global mode and local mode."""
import importlib
import init
x = init.x
y = init.y


def viewer():
    """View."""
    print('x =' + str(x))
    print('y =' + str(y))


def writer():
    """Write."""
    x = 'x'
    y = 'y'


def maker():
    """Make a global val. out of nowhere."""
    global z
    z = 'z'


def global_writer():
    """Write to home file"""
    init.x = 'x'
    init.y = 'y'


print('before')
viewer()
writer()
print('normal write')
viewer()
global_writer()
print('global write')
viewer()
maker()
print('z =' + str(z))
