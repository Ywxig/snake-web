//cut


                
function drow () {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    ctx.beginPath();
    ctx.rect(cordX, cerdY, widthImg, heightImg);
    ctx.fillStyle = "#FF0000";
    ctx.fill();

    ctx.font = "62px Verdana";
    ctx.textAlign = "center";
    ctx.fillText(text_game_status, 405, 550);

    ctx.font = "32px Verdana";
    ctx.textAlign = "center";
    ctx.fillText(score, 240, 110);

    ctx.font = "22px Verdana";
    ctx.fillStyle = "#0000FF";
    ctx.textAlign = "center";
    ctx.fill()
    ctx.fillText(speed, 680, 110);


    ctx.closePath();
    cordY_anemi = cordY_anemi + speed;
}