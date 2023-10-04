const h1_pattern = /^\#\s/;
const h2_pattern = /^\##\s/;
const h3_pattern = /^\###\s/;
const h4_pattern = /^\####\s/;
const h5_pattern = /^\#####\s/;
const h6_pattern = /^\######\s/;
const img_inside_elem_pattern = /^  <img.+?(?=\>)/

const wrapper = document.getElementById("wrapper")

function addElem(html) {
    wrapper.insertAdjacentHTML('beforeend', html);
}



function process(str, allLines, currentLine) {
    if (h6_pattern.test(str)) {
        addElem("<h6>" + str.slice(7) + "</h6>");
        return 0;
    }
    if (h5_pattern.test(str)) {
        addElem("<h5>" + str.slice(6) + "</h5>");
        return 0;
    }
    if (h4_pattern.test(str)) {
        addElem("<h4>" + str.slice(5) + "</h4>");
        return 0;
    }
    if (h3_pattern.test(str)) {
        addElem("<h3>" + str.slice(4) + "</h3>");
        return 0;
    }
    if (h2_pattern.test(str)) {
        addElem("<h2>" + str.slice(3) + "</h2>");
        return 0;
    }
    if (h1_pattern.test(str)) {
        addElem("<h1>" + str.slice(2) + "</h1>");
        return 0;
    }
    if (img_inside_elem_pattern.test(str)) {
        addElem(allLines[currentLine-1] + str + allLines[currentLine+1]);
        return 1;
    }
    return 0;
}



function lines(txt) {
    return txt.split('\n');
}

async function asyncFetch(page) {
    const resp = await fetch(page);
    return resp.text();
}

async function readPage(page) {
    let liners = await lines(await asyncFetch(page))
    console.log(liners)
    for (let i = 0; i < liners.length; i++) {
        i += process(liners[i], liners, i)
    }
}

readPage("https://raw.githubusercontent.com/Bigmancozmo/BMC-ENGINE/beta/README.md");