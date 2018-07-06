
imgDecor = {}
hero = {}
hero.colonne = 1
hero.ligne = 1

imgDecor[0] = love.graphics.newImage("IMG/bg_green.png")
imgDecor[1] = love.graphics.newImage("IMG/bg_wood.png")
imgHero = love.graphics.newImage("IMG/Hero.jpg")

function love.load()

	love.window.setTitle("Fuck Fuck Fuck!")
	love.window.setMode(900, 580)

	map = {}

	map[1] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
	map[2] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[3] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[4] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[5] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[6] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[7] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[8] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[9] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[10] ={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[11] ={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[12] ={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[13] ={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[14] ={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[15] ={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[16] ={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[17] ={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	map[18] ={ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }

end

function love.update(dt)

end

function love.draw()

	love.graphics.scale(2, 2)

	local colonne
	local ligne
	for ligne=0,17 do
		for colonne=0,24 do
			love.graphics.draw(imgDecor[map[ligne+1][colonne+1]],
			colonne*16, ligne*16)
		end
	end
	
	love.graphics.draw(imgHero, (hero.colonne-1)*16, (hero.ligne-1)*16)

end

function love.keypressed(touche)

	if touche == "right" then
		if map[hero.ligne][hero.colonne+1] == 0 then
			hero.colonne = hero.colonne + 1
		end
	end
	if touche == "left" then
		if map[hero.ligne][hero.colonne-1] == 0	then
			hero.colonne = hero.colonne - 1
		end
	end
	if touche == "down" then
		if map[hero.ligne+1][hero.colonne] == 0	then
			hero.ligne = hero.ligne + 1
		end
        end
	if touche == "up" then
		if map[hero.ligne-1][hero.colonne] == 0	then
			hero.ligne = hero.ligne - 1
		end
        end

end