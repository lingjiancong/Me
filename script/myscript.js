
var store = document.getElementById("selectStore")

// 香港, apm Hong Kong
var v1 = "R673"
// 香港, Canton Road
var v2 = "R499"
// 香港, Causeway Bay
var v3 = "R409"
// 香港, Festival Walk
var v4 = "R485"
// 香港, ifc mall
var v5 = "R428"
// 香港, New Town Plaza
var v6 = "R610"

//store.options[ store.selectedIndex ].value

store.value = v1

function callClickEvent(element){
    var evt = document.createEvent("HTMLEvents"); 
    evt.initEvent("click", true, true); 
    element.dispatchEvent(evt);
}

function callOnChangeEvent(element){
    var evt = document.createEvent("HTMLEvents"); 
    evt.initEvent("onchange", true, true); 
    element.dispatchEvent(evt);
}