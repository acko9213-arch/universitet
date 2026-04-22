const modal  = document.getElementById("modalid");
const modal1 = document.getElementById("modalid1");
const open   = document.getElementById("open");
const open1  = document.getElementById("open1");
const open2  = document.getElementById("but1");
const close  = document.querySelector(".close");
const close1 = document.querySelector(".close1");
const close3  = document.getElementById("but2");

open.onclick = function () {
    modal.style.display = "block";
}

open1.onclick = function () {
    modal.style.display = "block";
}

close.onclick = function () {
    modal.style.display = "none";
}

close3.onclick = function () {
    modal1.style.display = "none";
}

open2.onclick = function () {
    modal.style.display  = "none";
    modal1.style.display = "block";
}

close1.onclick = function () {
    modal1.style.display = "none";
}

window.onclick = function (event) {
    if (event.target == modal)  modal.style.display = "none";
    if (event.target == modal1) modal1.style.display = "none";
}