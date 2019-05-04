function change() {
    for (var i = 1; i <= 20; i++)
        document.getElementById("pic").style.backgroundPositionY = "(50-600*i)px";
}
setInterval("change()",1000);
