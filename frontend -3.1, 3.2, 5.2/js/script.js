var modal = document.getElementById('modal_form');
var body = document.body;

var closeButtom = document.getElementsByClassName('close_buttom')[0];
closeButtom.addEventListener('click', closeModal);

var openButtom = document.getElementById('write_me');
openButtom.addEventListener('click', showModalWindow);

function showModalWindow() {
    modal.style.display = 'block';
    body.style.overflowY = 'hidden';
}

function closeModal() {
    modal.style.display = 'none';
    body.style.overflowY = 'auto';
}

window.onclick = function (event) {
    if (event.target == modal) {
        modal.style.display = "none";
        body.style.overflowY = 'auto';
    }
}

window.onload = function () {
    showModalWindow();
    closeModal();
    validateForm();
    showAllFilms();
}

function showAllFilms() {
    document.getElementById('show_all_films').addEventListener('click', showMoreFilms);
    
    function showMoreFilms() {
        document.getElementById('show_all_films').style.display = 'none';
        document.getElementById('container_button').style.display = 'none';
        document.getElementById('more_films').classList.add('show_more_films');
    }
}

function validateForm() {
    var form = document.getElementById('modal_window');
    form.addEventListener('submit', validate);
    
    function validate() {
        
        
        var requiredFields = document.getElementsByClassName('input_text');
        for (var i = 0; i < requiredFields.length; i++) {
            if (!requiredFields[i].value) {
                requiredFields[i].classList.add('require');
                
            }
            event.preventDefault();
        }
    }
    
    var requiredFields = document.getElementsByClassName('input_text');
    for (var i = 0; i < requiredFields.length; i++) {
        requiredFields[i].addEventListener('click', function () {
            this.classList.remove('require');
        });
    }
}

