fetch("cards.xml")
    .then(res => res.text())
    .then(str => new DOMParser().parseFromString(str, "text/xml"))
    .then(xml => {
        const products = xml.getElementsByTagName("product");
        const container = document.querySelector(".cards");
        const range = document.getElementById("price");
        const output = document.getElementById("out");
        const markSelect = document.querySelectorAll(".mark select")[0];

        let allCards = [];

        for (let p of products) {
            const name = p.getElementsByTagName("name")[0].textContent;
            const price = p.getElementsByTagName("price")[0].textContent;
            const desc = p.getElementsByTagName("description")[0].textContent;
            const img = p.getElementsByTagName("image")[0].textContent;

            const card = document.createElement("div");
            card.className = "card";
            card.dataset.price = price;
            card.dataset.mark = name.split(" ")[0];

            const image = document.createElement("img");
            image.src = img;

            const title = document.createElement("h3");
            title.textContent = name;

            const otstup = document.createElement("p");
            otstup.textContent = "от";
            otstup.classList.add("ot");

            const priceEl = document.createElement("p");
            priceEl.textContent = Number(price).toLocaleString("ru-RU") + " BYN";
            priceEl.classList.add("cena12345");

            const d = document.createElement("p");
            d.textContent = desc;
            d.classList.add("cena123456");

            const button = document.createElement("button");
            button.textContent = "Подробнее";
button.addEventListener("click", () => {
    localStorage.setItem("carId", p.getAttribute("id")); 
    window.location.href = "car.html";
});
            const div123 = document.createElement("div");
            div123.classList.add("div123");
            div123.append(otstup, priceEl);

            card.append(title, image, div123, d, button);
            allCards.push(card);
        }

        function pols() {
    const max = Number(range.value);
    const selectedMark = markSelect.value;
    container.innerHTML = "";

    const filtered = allCards.filter(card => {
        const price = Number(card.dataset.price) <= max;
        const mark = !selectedMark || card.dataset.mark === selectedMark;
        return price && mark;
    });


    filtered.sort((a, b) => Number(a.dataset.price) - Number(b.dataset.price));

    filtered.forEach(card => container.appendChild(card));
}
const params = new URLSearchParams(window.location.search);
const markFromUrl = params.get("mark");

if (markFromUrl) {
    markSelect.value = markFromUrl;
}

        output.textContent = range.value;
        pols();

        range.addEventListener("input", () => {
            output.textContent = range.value;
            pols();
        });

        markSelect.addEventListener("change", () => {
            pols();
        });
    });
    