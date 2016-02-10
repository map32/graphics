var c = document.getElementById("candy");
ctx = c.getContext("2d");
ctx.fillStyle = "#FF0000";
var dx, dy;
var pretty = function(e){
    var r = c.getBoundingClientRect();
    var x = e.clientX - r.left;
    var y = e.clientY - r.top;
    ctx.beginPath();
    ctx.moveTo(dx,dy);
    ctx.lineTo(x,y);
    dx = x;
    dy = y;
    ctx.stroke();
    ctx.beginPath();
    ctx.arc(x,y,5,0,Math.PI*2);
    ctx.fill();
    ctx.stroke();
}
var refresh = function(){
    ctx.clearRect(0,0,500,500);
}
var kirkles = function(){
    
}
ctx.beginPath();
c.addEventListener('click', pretty);
