
document.getElementsByClassName("bu")[0].addEventListener("click", function () {
    let name = document.getElementById("name").value;
    let sname = document.getElementById("sname").value;
    let f = document.getElementById("f").value;
    let email = document.getElementById("email").value;
    let number = document.getElementById("number").value;
    let fa = document.getElementById("fa").value;
    let g = document.getElementById("g").value;
    let c = document.getElementById("c").value;

        const qwe = Array.from(
        document.querySelectorAll("#qwe input:checked")).map(input => input.id);
    

    let fo = document.getElementById("fo");
    fo.innerHTML = `
        <p>Имя: ${name}</p>
        <p>Отчество: ${sname}</p>
        <p>Фамилия: ${f}</p>
        <p>Email: ${email}</p>
        <p>Телефон: ${number}</p>
        <p>Соцсети: ${qwe.join(", ")}</p>
        <p>Факультет: ${fa}</p>
        <p>Группа: ${g}</p>
        <p>Курс: ${c}</p>
    `
})
