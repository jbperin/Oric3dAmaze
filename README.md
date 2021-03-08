# Oric3dAmaze
Yet Another Maze Game for Oric



git clone https://github.com/jbperin/Oric3dAmaze.git

cd Oric3dAmaze/

cd contrib

git clone --depth=1 --branch=develop https://github.com/jbperin/OSME.git
rm -rf ./OSME/.git

git clone --depth=1 -- branch=develop https://github.com/oric-software/castoric.git
rm -rf ./castoric/.git

cd ..

cp contrib/OSME/ay_s.s ./src
cp contrib/OSME/keybuf_s.s ./src
cp contrib/OSME/kernel.s ./src
cp contrib/OSME/keyboard.s ./src
cp contrib/OSME/keyboard.s ./src
cp contrib/OSME/osme_s.s ./src
cp contrib/OSME/print.s ./src
cp contrib/OSME/task25hz.s ./src
cp contrib/OSME/tasks_s.s ./src
cp contrib/OSME/via.h ./src
cp contrib/castoric/proto/c/texel_s.s ./src
cp contrib/castoric/proto/c/raycast_s.s ./src
cp contrib/castoric/proto/c/dda_s.s ./src
cp contrib/castoric/proto/c/drawWalls_s.s ./src
cp contrib/castoric/proto/c/viewport_s.s ./src
cp contrib/castoric/proto/c/column_s.s ./src

cp contrib/castoric/proto/c/config.h ./src
cp contrib/castoric/proto/c/tabAdrTabIdxRd.h ./src


cp contrib/castoric/proto/c/dda.c         ./src
cp contrib/castoric/proto/c/drawWalls.c   ./src
cp contrib/castoric/proto/c/game.c        ./src
cp contrib/castoric/proto/c/math.c ./src
cp contrib/castoric/proto/c/player.c ./src
cp contrib/castoric/proto/c/raycast.c ./src
cp contrib/castoric/proto/c/scene.c ./src
cp contrib/castoric/proto/c/texel.c ./src
cp contrib/castoric/proto/c/viewport.c ./src


cp contrib/castoric/proto/c/constants.h ./src
cp contrib/castoric/proto/c/tabIdxRdTexture.h ./src
cp contrib/castoric/proto/c/tablogtrigo.h ./src
cp contrib/castoric/proto/c/tabMulti.h ./src
cp contrib/castoric/proto/c/tabrayangle.h ./src
cp contrib/castoric/proto/c/tabTexelColor.h ./src
cp contrib/castoric/proto/c/tabunfish.h ./src
cp contrib/castoric/proto/c/tabunlogd2hh.h ./src
cp contrib/castoric/proto/c/texture_bluestone.h ./src
cp contrib/castoric/proto/c/texture_christmas.h ./src
cp contrib/castoric/proto/c/texture_logo.h ./src
cp contrib/castoric/proto/c/texture_pillar.h ./src
cp contrib/castoric/proto/c/texture_redbrick.h ./src
