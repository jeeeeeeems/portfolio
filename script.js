window.addEventListener('scroll', function() {
    let sections = document.querySelectorAll('section');
    let navLinks = document.querySelectorAll('.navbar ul li a');

    sections.forEach((section, index) => {
        let sectionTop = section.offsetTop - 60;
        let sectionBottom = sectionTop + section.offsetHeight;

        console.log(`Section ${section.id}: top = ${sectionTop}, bottom = ${sectionBottom}, scrollY = ${window.scrollY}`);

        if (window.scrollY >= sectionTop && window.scrollY < sectionBottom) {
            navLinks.forEach(link => link.classList.remove('active'));
            navLinks[index].classList.add('active');
        }
    });
});
