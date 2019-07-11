"""Program to check vector field visualization with Plotly"""
import numpy as np
import plotly.offline as ply
import plotly.graph_objs as go


def Vecdatas():
    """Make vector datas to plot."""
    Ntot = 10
    global x, y, z, u, v, w
    x = np.random.rand(Ntot)
    y = np.random.rand(Ntot)
    z = np.random.rand(Ntot)
    u = np.random.rand(Ntot)
    v = np.random.rand(Ntot)
    w = np.random.rand(Ntot)


def visCart(x, y, z, u, v, w):
    """Cartesian vector visualization."""
    """Source : https://plot.ly/~empet/14971/vector-field-visualization-wit/#/"""

    # datas to plot. type: dictionary
    cones = dict(type='cone',
                    x=x.flatten(),
                    y=y.flatten(),
                    z=z.flatten(),
                    u=u.flatten(),
                    v=v.flatten(),
                    w=w.flatten(),
                    sizemode='scaled',
                    sizeref=2,
                    showscale=True,
                    anchor='tail'
                 )

    # make layout dictionary, 'Cone plot' etc are default value.
    def get_layout(title='Cone Plot.html', width=800, height=800, aspect=[1, 1, 1]):
        axis = dict(showbackground=True,
                    backgroundcolor="rgb(235, 235,235)",
                    gridcolor="rgb(255, 255, 255)",
                    zerolinecolor="rgb(255, 255, 255)",
                    )
        return dict(title=title,
                    width=width,
                    height=height,
                    autosize=False,
                    scene=dict(camera=dict(eye=dict(x=1.15, y=1.15, z=0.6)),
                               xaxis=dict(axis),
                               yaxis=dict(axis),
                               zaxis=dict(axis),
                               aspectratio=dict(x=aspect[0],
                                                y=aspect[1],
                                                z=aspect[2]))
                    )

    fig1 = dict(data=[cones],
                    layout=get_layout(title='The cone plot of the ABC-flow',
                                      width=650,
                                      height=600
                                      )
                )
    ply.plot(fig1, filename='cones-ABC.html', auto_open=True)


"""main part"""
Vecdatas()
visCart(x, y, z, u, v, w)
