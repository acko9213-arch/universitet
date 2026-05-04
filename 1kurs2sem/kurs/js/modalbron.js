document.addEventListener("click", function (e) {

const modal = document.getElementById("modalwindow");
const modal1 = document.getElementById("modalid1");

if (e.target.closest(".kredit1")) {
    modal.style.display = "block";
}

if (e.target.closest(".krest")) {
    modal.style.display = "none";
}

if (e.target === modal) {
    modal.style.display = "none";
}

});


document.querySelector(".forma").addEventListener("submit", function(e){

e.preventDefault();

if(!this.checkValidity())
{
    this.reportValidity();
    return;
}

document.getElementById("modalwindow").style.display="none";
document.getElementById("modalid1").style.display="block";

});