import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

datos=np.loadtxt("datos.dat")
nx=datos.shape[1]
nt=datos.shape[0]

datosx, datosy=np.linspace(0,1,nx), [] 
plot, ax = plt.subplots()
ax.grid()
ln, = plt.plot(datosx, datos[0])

def init():  
    ax.set_xlim(0, 1)
    ax.set_ylim(-0.5, 0.5)
    ax.set_xlabel("Posicion [metros]")
    ax.set_ylabel("U")
    return ln,
def animate(i):
    ln.set_ydata(datos[i])
    ax.set_title("Tiempo: "+ str("{0:.2f}".format(2*i/(nt-1)))+ " segundos")
    return ln,


ani = animation.FuncAnimation(plot, animate, init_func=init, interval=100,frames=range(int(nt/10)), blit=True,repeat=True)

ani.save("30GIF.gif",fps=10)

