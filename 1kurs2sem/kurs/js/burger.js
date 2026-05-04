const burger = document.getElementById('burger');
const burgerMenu = document.getElementById('burgermenu');
const burgerOverlay = document.getElementById('burgerreal');
const header = document.querySelector('header');

function getHeaderBottom() {
  return header.getBoundingClientRect().bottom;
}

function setMenuTop() {
  const h = getHeaderBottom();
  burgerMenu.style.top = h + 'px';
  burgerMenu.style.height = `calc(100% - ${h}px)`;
  burgerOverlay.style.top = h + 'px';
}

function openMenu() {
  setMenuTop();
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

burger.addEventListener('click', () => {
  if (burgerMenu.classList.contains('active')) {
    closeMenu();
  } else {
    openMenu();
  }
});

burgerOverlay.addEventListener('click', closeMenu);

window.addEventListener('resize', () => {
  if (burgerMenu.classList.contains('active')) setMenuTop();
});