let menuOptions = [];
let menuIndex = 0;

const screenMenus = {
    title: ['START','EXIT'],
    camp_entrance: ['ENTER CAMP','EXPLORE SURROUNDINGS','CHECK INVENTORY'],
    bonfire: ['STEP 1 : PICK UP WOOD','STEP 2 : STACK WOOD','STEP 3 : LIGHT FIRE'],
    command_tent: ['TYPE "HELP"','TYPE "START"','TYPE "CLEAR"','TYPE "STATUS"'],
    escape_run: ['MOVE UP','MOVE LEFT','MOVE DOWN','MOVE RIGHT'],
    trail: ['PATH A : DARK FOREST','PATH B : SUNNY GLADE','PATH C : MYSTIC STREAM']
};

function updateMenuOptions() {
    menuOptions = screenMenus[gameState.currentArea] || [];
    menuIndex = 0;
}
