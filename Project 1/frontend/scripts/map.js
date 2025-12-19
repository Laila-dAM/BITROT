function mapSelectionToScreen(selection) {
    switch(selection) {
        case 'START':
        case 'CONTINUE':
        case 'RESTART':
        case 'PLAY AGAIN':
            return 'intro';
        case 'EXIT':
            window.close();
            return null;
        case 'ENTER CAMP': return 'camp_entrance';
        case 'EXPLORE SURROUNDINGS': return 'forest_start';
        case 'CHECK INVENTORY': return 'command_tent';
        case 'STEP 1 : PICK UP WOOD':
        case 'STEP 2 : STACK WOOD':
        case 'STEP 3 : LIGHT FIRE': return 'bonfire';
        case 'ENTER CITY':
        case 'REVIEW STATS': return 'city_gate';
        case 'TYPE "HELP"':
        case 'TYPE "START"':
        case 'TYPE "CLEAR"':
        case 'TYPE "STATUS"': return 'command_tent';
        case 'MOVE UP':
        case 'MOVE LEFT':
        case 'MOVE DOWN':
        case 'MOVE RIGHT': return 'escape_run';
        case 'TRY TO ESCAPE':
        case 'STRUGGLE':
        case 'OBSERVE': return 'forest_event';
        case 'TRACK ANIMAL':
        case 'IGNORE':
        case 'SET TRAP':
        case 'RUN': return 'hunt_zone';
        case 'FUNCTION open_door(code)':
        case 'FUNCTION collect_sample()':
        case 'FUNCTION transmit_data()': return 'laboratory';
        case 'FIX':
        case 'RESTART':
        case 'VALIDATE': return 'medical_tent';
        case 'INVESTIGATE':
        case 'REPAIR':
        case 'NAVIGATE':
        case 'WAIT': return 'night_zone';
        case 'PATH A : DARK FOREST':
        case 'PATH B : SUNNY GLADE':
        case 'PATH C : MYSTIC STREAM': return 'trail';
        case 'PUSH':
        case 'POP':
        case 'ENQUEUE':
        case 'DEQUEUE': return 'warehouse';
        case 'PATROL SECTOR 1':
        case 'PATROL SECTOR 2':
        case 'PATROL SECTOR 3':
        case 'AUTOMATE ROUTINE': return 'watchtower';
        case 'VIEW STATS':
        case 'CHECK LOGS':
        case 'DEPLOY UPDATE':
        case 'REVIEW USERS': return 'advanced_panel';
        default: return 'title';
    }
}
