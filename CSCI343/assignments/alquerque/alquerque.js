// Name: Olivia Lau
// File : alquerque_EC.js
// Class: CSCI 343 Graphics
// Assignment: #2 Alquerque
// Date: September 24, 2015
// Purpose: Plays the game Alquerque with a referee

var canvas;
var gl;
var index = 0;
var vbuffer;
var squareCenter = [ ];
var squareSide = 0.05;
var boardColor;
var vColor = [ ];
var vertices = [ ];

var red = vec4(0.7, 0, 0.3, 0.5);
var blue = vec4(0, 0.9, 0.9, 1);
var white = vec4(1, 1, 1, 0);
var gamePieces = [ ];              // array to hold player's game piece
var clicks = 0;
var lastClick = 0;
var player = 1;

// variables for board size
var x = -0.9;
var y = -0.9;
var side = 1.8;

window.onload = function init() {
    canvas = document.getElementById( "gl-canvas" );
    
    gl = WebGLUtils.setupWebGL( canvas );
    if ( !gl ) { alert( "WebGL isn't available" ); }
    gl.viewport( 0, 0, canvas.width, canvas.height );
    gl.clearColor( 0.8, 0.8, 0.8, 0.835 );
    var program = initShaders( gl, "vertex-shader", "fragment-shader" );
    gl.useProgram( program );

    // initialize the board and reset the pieces
    boardColor = vec4( 0, 0, 0, 1);
    board( x, y, side );
    
    vBuffer = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(vertices), gl.STATIC_DRAW );
    var vPos = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer( vPos, 2, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vPos );
    
    vColorLoc = gl.getUniformLocation( program, "vColor" );
    
    // the two mouse click events
    canvas.addEventListener( "click", mouseResponse );
    document.getElementById("Restart").onclick = restart;
    render();
}

function render() {
    gl.clear( gl.COLOR_BUFFER_BIT );
    gl.uniform4fv( vColorLoc, boardColor);
    
    // draws outline and X
    gl.drawArrays(gl.LINE_LOOP, 0, 8);
    // draws tilted square
    gl.drawArrays(gl.LINE_LOOP, 8, 4);
	// draws horizontal and vertical lines
    for(var i = 0; i < 6; i++) {
        gl.drawArrays( gl.LINES, 12+(2*i), 2 );
    }
    
    // draw the game pieces
    for(var i = 0; i < index; i++) {
    
     	// determines color of piece
    	if( gamePieces[i] == 1 )
    		gl.uniform4fv(vColorLoc, red);
    	else if( gamePieces[i] == 2 )
    		gl.uniform4fv(vColorLoc, blue);
    		
    	if( gamePieces[i] != 0 )
    		gl.drawArrays(gl.TRIANGLES, 32+(i*6), 6);
    }
    window.requestAnimFrame(render);
}

// function to draw the board
function board( x, y, side ) {
	// the outline of the board
	vertices.push( vec2(x, y), vec2(x+side, y), vec2(x+side, y+side), 
		vec2(x, y+side) );
		
	// the X on the board
	vertices.push( vec2(x, y), vec2(x+side, y+side), 
		vec2(x+side, y), vec2(x, y+side) );
		
	// the tilted square inside the board
	vertices.push( vec2(x+(side/2), y), vec2(x+side, y+(side/2)),
		vec2(x+(side/2), y+side), vec2(x, y+(side/2)) );
		
	// vertical and horizontal lines
	for( var i = 1; i < 6; i++) {
		vertices.push( vec2(x+i*(side/4), y ), vec2(x+i*(side/4), y+side) );
		vertices.push( vec2(x, y+i*(side/4) ), vec2(x+side, y+i*(side/4)) );
	}
	
	//call to initialize the board
	initialize();
}

// function to draw the squares
function square( x, y, side) {
	vertices.push( vec2(x-side/2, y+side/2) );
	vertices.push( vec2(x+side/2, y+side/2) );
	vertices.push( vec2(x-side/2, y-side/2) );
	vertices.push( vec2(x+side/2, y+side/2) );
	vertices.push( vec2(x-side/2, y-side/2) );
	vertices.push( vec2(x+side/2, y-side/2) );
	
	index++;

}

// function to reset the board
function initialize() {
	restart();
	
    for( var i = 0; i < 25; i++ )		
    	square( squareCenter[i][0], squareCenter[i][1], squareSide);
}

// resets board pieces to starting location
function restart() {
	var spacing = side/4;

	console.log("----- Restarting game -----");
	
	clicks = 0;
	player = 1;
	lastClick = 0;
	
	// makes all the squares at each intersection position [i, j]
	for( var i = 0; i < 5; i++ ) {
		for( var j = 0; j < 5; j++ ) {
			var position = (i*5)+j;
			squareCenter.push( vec2( (x+(j*spacing)), (y+(i*spacing)) ) );
    			
    		// sets player number to the 2 columns on either side
    		if( j == 0 || j == 1 ) {
    			gamePieces[ position ] = 1;
    		} else if( j == 3 || j == 4 ) {
    			gamePieces[ position ] = 2;
    		}
    		
    		// sets player number and color to middle column
    		if( j == 2 && (i == 0 || i == 1)) {
    			gamePieces[ position ] = 2;
    		} else if( j == 2 && (i == 3 || i ==4)) {
    			gamePieces[ position ] = 1;
    		} else if( j == 2 && i == 2 ) {
    			gamePieces[ position ] = 0;
    		}
    	}
	}
}

// function for clicking the game pieces
function mouseResponse(event) {

	var valid = false;    // flag for a valid move
	var t = vec2((2*(event.clientX-10)/canvas.width)-1, 
		(2*(canvas.height - (event.clientY-10))/canvas.height)-1);
				
	for( var i = 0; i < 25; i++) {
		var xMax = squareCenter[i][0] + squareSide/2.0;
		var yMax = squareCenter[i][1] + squareSide/2.0;
		var xMin = squareCenter[i][0] - squareSide/2.0;
		var yMin = squareCenter[i][1] - squareSide/2.0;

		if( t[0] <= xMax && t[0] >= xMin && t[1] <= yMax && t[1] >= yMin ) {
			valid = true;
			clicks++;

			print("Location " + (i+1) + " selected");
			
			//first click
			if( clicks % 2 == 1 ) {
				// if the first click is an empty spot
				if( gamePieces[i] == 0 ) {
					clicks--;
					print("Click a piece to move");
				} else { // checks if its the correct player
					if( checkPlayer(i) == true ) {
						lastClick = i;
					} else {
						clicks--;
						print("Wrong player");
					}
				}
			} else { // second click
				if( !checkPlayer(i)  || gamePieces[i] == 0 ) {
					if( validate(i, lastClick) == true ) {
						update(i, lastClick);
						player = player == 1? 2 : 1;
						lastClick = i;
					} else {
						clicks--;
						print("Invalid move, try again");
					}
				} else { // clicks same color piece twice
					clicks--;
					print("Can not delete your own pieces");
				}
				
				// resets the game if there is a winner
				checkWinner();
				
			} // end of else for second click
		} // end of if
	}
	
	if( valid == false) {
		print("Invalid location.");
	}
}

// switches the pieces
function update(newPos, oldPos) {
	// changes color of the pieces
	vColor[newPos] = vColor[oldPos];
	
	// changes player number and sets the old position to 0
	gamePieces[newPos] = gamePieces[oldPos];
	gamePieces[oldPos] = 0;
}

// checks if move from old position to new position is valid
function validate(newPos, oldPos) {
	var difference = Math.abs(newPos - oldPos);
	
	// arrays to hold the old position that can move either 4 or 6 positions
	var difference_four = [2, 4, 6, 8, 12, 14, 16, 18, 20, 22]
	var difference_six = [0, 2, 6, 8, 10, 12, 16, 18, 22, 24]
	//console.log("d"+difference); 
	// checks left/right
	if( difference == 1 )
		return true;
	
	// checks vertical
	if( Math.trunc(newPos/5) == Math.trunc(oldPos/5) ) {
		for( var x = oldPos+1; x < newPos; x++ ) {
			if( gamePieces[x] != 0 )
				return false;
		}
		return true;
	}
	
	// checks up/down
	if( difference % 5 == 0 ) {
		if( difference != 5 ) {
			for( var x = oldPos+5; x < newPos; x+=5 )
				if( gamePieces[x] != 0 )
					return false;
		}
		return true;
	}
	
	// checks for diagonal moves
	if( difference % 6 == 0 ) {
		for ( var i = 0; i < 10; i++ ){
			if( oldPos == difference_six[i]) {
				if( difference != 6 ) {
					for( var x = oldPos+6; x < newPos; x+=6 )
						if( gamePieces[x] != 0){
							console.log(x+ ": " + gamePieces[x]);
							return false;
						}
				}
				return true;
			}
		}
	}
	if( difference % 4 == 0 ) {
		for ( var i = 0; i < 10; i++ ){
			if( oldPos == difference_four[i]) {
				if( difference != 4 ) {
					for( var x = oldPos+4; x < newPos; x+=4 )
						if( gamePieces[x] != 0)
							return false;
				}	
				return true;
			}
		}
	}
	return false;

}

// checks if the player and the piece clicked corresponds
function checkPlayer(i) {
	if(gamePieces[i] == player)
		return true;
	return false;
}

// checks if there is a winner
function checkWinner() {
	var player1 = false;    // false for no game pieces on the board
	var player2 = false;
	
	for( var i = 0; i < 25; i++ ) {
		if( gamePieces[i] == 1 )
			player1 = true;
		else if( gamePieces[i] == 2 )
			player2 = true;
	}
	
	if( player1 == false ) {
		window.alert("Player 2 has won!");
		restart();
	} else if( player2 == false ) {
		window.alert("Player 1 has won!");
		restart();
	}
}

// print function to print the current player number at the beginning
function print(string) {
	console.log("Player " + player + ": " + string);
}







