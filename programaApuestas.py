# Programa para poder tener un registro de las apuestas 

# Bibliotecas utilizadas

import tkinter as tk


# BACK END
class apuesta: # Nombre de nuestra clase

    # Atributos de nuestra clase
    def __init__(self, mes, concepto, montoApuesta, gananciaApuesta = None, estadoApuesta = None):
        self.mes = mes  # Se usara para catalogar el mes donde se subio la apuesta
        self.concepto = concepto 
        self.montoApuesta = montoApuesta
        self.gananciaApuesta = gananciaApuesta
        self.estadoApuesta = estadoApuesta

    # Se usa para indicar como se imprimira la informacion 
    def __str__(self):
        return f"Mes: {self.mes} \n Concepto: {self.concepto} \n Monto apostado: ${self.montoApuesta} \n Ganancia apuesta: {self.gananciaApuesta} \n Estado Apuesta: {self.estadoApuesta} "

    def cambiar_estado_ganada (self):
        self.estadoApuesta = True
        return "Apuesta ganada"
    
    def cambiar_estado_perdida(self):
        self.estadoApuesta = False
        return "Apuesta perdida"


# Lista donde se guardaran todas las apuestas realizadas
apuestasRealizadas = []
apuestasGanadas = []
apuestasPerdidas = []

# Datos para crear el objeto
mes = input("Ingrese la fecha: ")
concepto = input("Ingrese la descripcion de la apuesta: ")
montoApuesta = int(input("Ingrese la cantidad apostada: "))

montoApuesta = -abs(montoApuesta) # Se usa el "-abs" para siempre tener el numero negativo que es lo apostado

nuevaApuesta = apuesta(mes, concepto, montoApuesta) 

print(nuevaApuesta)


# FRONT END
class appApuestas:
    def __init__(self): # Se crea la ventana principal y se especifica su configuracion
        self.ventana = tk.Tk()
        self.ventana.title("Manejo de apuestas")
        self.ventana.geometry("800x600")
        self.ventana.configure(bg = "grey")
        self.crear_widgets()

    def crear_widgets(self):
        # Se crea el titulo principal 
        tituloPrincipal = tk.Label(self.ventana, text = "Manejo de apuestas", font = ("Arial", 35), fg = "blue")
        tituloPrincipal.pack()

        # Se crea el lado izquierdo donde se ingresara la apuesta
        frame_izquierdo = tk.Frame(self.ventana, relief = "ridge", bd = 2)
        frame_izquierdo.pack(side = 'left')

        titulo_frame_izquierdo = tk.Label(frame_izquierdo, text = "Subir nueva apuesta", font = ("Arial", 15), fg = "red", bg = "white")
        titulo_frame_izquierdo.pack()

    def ejecutar(self):
        self.ventana.mainloop()
    
# Se crea la app
aplicacion = appApuestas()
aplicacion.ejecutar()

    
