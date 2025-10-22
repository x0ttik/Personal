let pila = [];

function apilar() {
    let valor = document.getElementById("valor").value;
    if (valor === "") return;

    pila.push(valor);
    mostrarPila();
    document.getElementById("valor").value = "";
}

function desapilar() {
    if (pila.length === 0) return;

    // animar eliminacion del primer elemento
    const contenedor = document.getElementById("contenedor");
    const primeraCaja = contenedor.firstElementChild;

    if (primeraCaja) {
        primeraCaja.style.animation = "desaparecer 0.4s ease forwards";
        setTimeout(() => {
            pila.shift();  // elimina el primero 
            mostrarPila();
        }, 400); // espera a que termine la animacion
    }
}

function mostrarPila() {
    const contenedor = document.getElementById("contenedor");
    contenedor.innerHTML = "";
    for (let i = 0; i < pila.length; i++) {
        const div = document.createElement("div");
        div.className = "caja";
        div.textContent = pila[i];
        contenedor.appendChild(div);
    }
}