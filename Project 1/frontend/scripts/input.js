function handleInput(e) {
    if (menuOptions.length > 0) {
        if (e.key === 'w' || e.key === 'ArrowUp') menuIndex = (menuIndex - 1 + menuOptions.length) % menuOptions.length;
        if (e.key === 's' || e.key === 'ArrowDown') menuIndex = (menuIndex + 1) % menuOptions.length;

        if (e.key === 'Enter') {
            const selection = menuOptions[menuIndex];
            const next = mapSelectionToScreen(selection);
            if (next) {
                gameState.currentArea = next;
                updateMenuOptions();
                showScreen(gameState.currentArea, menuOptions, menuIndex);
                if (window.areas && areas[next]) areas[next](); // executa função da área modular
            } else {
                alert('Exiting game...');
            }
        }
    } else {
        if (e.key === 'Enter') {
            if (window.areas && areas[gameState.currentArea]) areas[gameState.currentArea]();
        }
    }
    showScreen(gameState.currentArea, menuOptions, menuIndex);
}

function mapSelectionToScreen(selection) {
    switch(selection) {
        case 'START': return 'intro';
        case 'CONTINUE': return 'camp_entrance';
        case 'ENTER CAMP': return 'camp_entrance';
        case 'EXPLORE SURROUNDINGS': return 'trail';
        case 'CHECK INVENTORY': return 'command_tent';
        case 'STEP 1 : PICK UP WOOD':
        case 'STEP 2 : STACK WOOD':
        case 'STEP 3 : LIGHT FIRE': return 'bonfire';
        case 'MOVE UP':
        case 'MOVE LEFT':
        case 'MOVE DOWN':
        case 'MOVE RIGHT': return 'escape_run';
        default: return gameState.currentArea;
    }
}
