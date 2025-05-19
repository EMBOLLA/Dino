const dino = document.getElementById("dino");
const obstacle = document.getElementById("obstacle");
let jumping = false;

document.addEventListener("keydown", function(event) {
    if (event.code === "Space" && !jumping) {
        jumping = true;
        let jumpHeight = 0;
        let upInterval = setInterval(() => {
            if (jumpHeight >= 100) {
                clearInterval(upInterval);
                let downInterval = setInterval(() => {
                    if (jumpHeight <= 0) {
                        clearInterval(downInterval);
                        jumping = false;
                    }
                    jumpHeight -= 5;
                    dino.style.bottom = jumpHeight + "px";
                }, 20);
            }
            jumpHeight += 5;
            dino.style.bottom = jumpHeight + "px";
        }, 20);
    }
});

function moveObstacle() {
    let obstaclePosition = 600;
    let moveInterval = setInterval(() => {
        if (obstaclePosition < 0) {
            obstaclePosition = 600;
        } else {
            obstaclePosition -= 5;
        }
        obstacle.style.right = obstaclePosition + "px";

        
        if (obstaclePosition < 90 && obstaclePosition > 50 && parseInt(dino.style.bottom) < 40) {
            alert("Game Over !");
            clearInterval(moveInterval);
            location.reload();
        }
    }, 30);
}

moveObstacle();