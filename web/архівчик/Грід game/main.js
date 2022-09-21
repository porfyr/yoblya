console.log("cj");

const plyty = [
    ["b1", "b2", 'b3'],
    ["b4", "b5", "b6"],
    ["b7", "b8", "b9"]
];

let cur_b = [1, 1];

function zminy() {
    document.getElementById(plyty[cur_b[0]][cur_b[1]]).style.background = "black";
    document.getElementById(plyty[cur_b[0]][cur_b[1]]).style.color = "aliceblue";
}


document.addEventListener('keydown', function(event) {
    switch (event.keyCode) {
        case 38:
            up();
            console.log("up");
            break;
        case 40:
            down();
            console.log("down");
            break;
        case 37:
            left();
            console.log("left");
            break;
        case 39:
            right();
            console.log("right");
            break;
    }
});

function up() {
    if (cur_b[0] !== 0) {
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]] ).style.background = "white";
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]] ).style.color = "black";
        
        document.getElementById(plyty[ cur_b[0]-1 ][cur_b[1]] ).style.background = "black";
        document.getElementById(plyty[ cur_b[0]-1 ][cur_b[1]] ).style.color = "aliceblue";
        cur_b[0]--;
    }
}
function down() {
    if (cur_b[0] !== 2) {
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]] ).style.background = "white";
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]] ).style.color = "black";
        
        document.getElementById(plyty[ cur_b[0]+1 ][cur_b[1]] ).style.background = "black";
        document.getElementById(plyty[ cur_b[0]+1 ][cur_b[1]] ).style.color = "aliceblue";
        cur_b[0]++;
    }
}
function left() {
    if (cur_b[1] !== 0) {
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]] ).style.background = "white";
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]] ).style.color = "black";
        
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]-1] ).style.background = "black";
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]-1] ).style.color = "aliceblue";
        cur_b[1]--;
    }
}
function right() {
    if (cur_b[1] !== 2) {
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]] ).style.background = "white";
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]] ).style.color = "black";
        
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]+1] ).style.background = "black";
        document.getElementById(plyty[ cur_b[0] ][cur_b[1]+1] ).style.color = "aliceblue";
        cur_b[1]++;
    }
}

//document.getElementById("napys").innerHTML = "nope";