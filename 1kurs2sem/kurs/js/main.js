function goToCar(id) {
    localStorage.setItem("carId", id);
    window.location.href = "car.html";
  }