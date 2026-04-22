const carId = localStorage.getItem("carId");

fetch("infocar.xml")
  .then(res => res.text())
  .then(str => new DOMParser().parseFromString(str, "text/xml"))
  .then(xml => {
    const items = xml.getElementsByTagName("info");
    let car = null;

    for (let item of items) {
      if (item.getAttribute("id") === carId) {
        car = item;
        break;
      }
    }

    if (!car) return;

    const get = tag => car.getElementsByTagName(tag)[0]?.textContent || "";

    document.title = get("namesite");
    document.querySelector(".car h1").textContent = get("name");
    document.querySelector(".high .lastone").textContent = get("name");
    document.querySelector(".avto").textContent = get("name");
    document.querySelector(".cennik").textContent = get("cena1");

    const images = [];
    for (let i = 1; i <= 8; i++) {
      const src = get("image" + i);
      if (src) images.push(src);
    }

    const sliderHTML = `
      <div class="slidu">
        <div class="slides" id="slides">
          ${images.map(src => `<div class="slide"><img src="${src}" alt=""></div>`).join("")}
        </div>
        <button class="r" id="prev">&#8249;</button>
        <button class="l" id="next">&#8250;</button>
      </div>
    `;

    const specsHTML = `
      <div class="carinfo">
        <div class="price0">  
        <div class="obprice">
          <p class="price1">${get("cena1")}</p>
          <p class="price2">${get("cena2")}</p>
          </div>
          <div class="obkredit">
          <button class="kredit1" id="kredit1">Забронировать</button>
          <p class="kredit2">${get("kredit")}</p>
          </div>
        </div> 
        <div class="specs">
          <div class="spec">Основные характеристики</div>
          <div class="spec"><span>Год</span><span class="spec1">${get("god")}</span></div>
          <div class="spec"><span>Двигатель</span><span class="spec1">${get("dvig")}</span></div>
          <div class="spec"><span>КПП</span><span class="spec1">${get("korob")}</span></div>
          <div class="spec"><span>Привод</span><span class="spec1">${get("privod")}</span></div>
          <div class="spec"><span>Мощность</span><span class="spec1">${get("moch")}</span></div>
        </div>
      </div>
    `;
     
    const krinfs = car.getElementsByTagName("krinf");
    const equipHTML = `
      <div class="equip">
        <h2>Дополнительная информация:</h2>
        <ul>
          ${Array.from(krinfs).map(k => `<li>${k.textContent}</li>`).join("")}
        </ul>
      </div>
    `;

    document.querySelector(".car").innerHTML += sliderHTML + specsHTML + equipHTML;

    let cur = 0;
    const slidesEl = document.getElementById("slides");

    function go(n) {
      cur = (n + images.length) % images.length;
      slidesEl.style.transform = `translateX(-${cur * 100}%)`;
    }

    document.getElementById("prev").onclick = () => go(cur - 1);
    document.getElementById("next").onclick = () => go(cur + 1);
  });
  