const burger = document.getElementById('burger');
const burgerMenu = document.getElementById('burgermenu');
const burgerOverlay = document.getElementById('burgerreal');
const burgerClose = document.getElementById('burgerclose');

function openMenu() {
    burger.classList.add('active');
    burgerMenu.classList.add('active');
    burgerOverlay.classList.add('active');
    document.body.style.overflow = 'hidden';
}

function closeMenu() {
    burger.classList.remove('active');
    burgerMenu.classList.remove('active');
    burgerOverlay.classList.remove('active');
    document.body.style.overflow = '';
}

burger.addEventListener('click', openMenu);
burgerClose.addEventListener('click', closeMenu);
burgerOverlay.addEventListener('click', closeMenu);


