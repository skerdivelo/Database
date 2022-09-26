let pippoDiv = document.getElementById("pippo");
pippoDiv.style.border = "5px solid red";

const ulTag = document.querySelector("ul");

function ClearList(){
    let liTags = document.querySelectorAll("ul>li");
    console.log(liTags);
    for(let i = 0; i < liTags.length; i++){
        ulTag.removeChild(liTags[i]);
    }
}

function AddToList(text, append = true){
    let elementToAdd = document.createElement("li");
    elementToAdd.innerHTML = text;
    if(append){
        ulTag.appendChild(elementToAdd);
    }else{
        ulTag.prepend(elementToAdd);
    }
}
ClearList();
AddToList("Primo");
AddToList("Secondo");
AddToList("Terzo");