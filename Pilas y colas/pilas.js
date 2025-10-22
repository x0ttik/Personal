const agregar = document.querySelector("#agregar")
const eliminar = document.querySelector("#eliminar")
const formatoPila = document.querySelector(".formatoPila")

// Contador para agregarle a la caja nueva
let contador = 1

agregar.addEventListener("click", () => {
    const nuevaCaja = document.createElement("div")
    nuevaCaja.classList.add("caja")

    const numero = document.createElement("h4")
    numero.classList.add("numero")
    numero.textContent = contador

    nuevaCaja.appendChild(numero)

    formatoPila.insertBefore(nuevaCaja, formatoPila.firstChild)

    contador = contador + 1

})

eliminar.addEventListener("click", () => {
    if (formatoPila.firstChild) {
        formatoPila.removeChild(formatoPila.firstChild)
        contador = contador - 1
    }
})