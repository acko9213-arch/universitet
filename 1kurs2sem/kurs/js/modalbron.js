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
if (e.target.closest("#BRON")) {
        modal.style.display = "none";
    modal1.style.display = "block";

    }
});