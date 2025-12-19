const screens = {};
let currentScreen = 'title';
let menuOptions = [];
let menuIndex = 0;

async function loadScreen(name) {
    const res = await fetch(`assets/ascii/screens/${name}.txt`);
    const text = await res.text();
    screens[name] = text.split('\n');
}

async function loadAllScreens() {
    const screenNames = [
        'title','intro','game_over','camp_entrance','bonfire',
        'command_tent','escape_run','trail','ending'
    ];
    for (let name of screenNames) await loadScreen(name);
}

function setMenu(options) {
    menuOptions = options;
    menuIndex = 0;
}

function showScreen() {
    const container = document.getElementById('game-screen');
    if (!screens[currentScreen]) return;
    const lines = screens[currentScreen].slice();
    menuOptions.forEach((opt, i) => {
        const lineIndex = lines.findIndex(line => line.includes(opt));
        if (lineIndex !== -1) lines[lineIndex] = (i === menuIndex ? '>' : ' ') + lines[lineIndex].slice(1);
    });
    container.textContent = lines.join('\n');
}

function handleInput(e) {
    if(menuOptions.length > 0) {
        if(e.key === 'w' || e.key === 'ArrowUp') menuIndex = (menuIndex - 1 + menuOptions.length) % menuOptions.length;
        if(e.key === 's' || e.key === 'ArrowDown') menuIndex = (menuIndex + 1) % menuOptions.length;
        if(e.key === 'Enter') selectOption(menuOptions[menuIndex]);
        showScreen();
    }
}

function selectOption(option) {
    switch(currentScreen) {
        case 'title':
            if(option === 'START') {
                currentScreen = 'intro';
                setMenu([]);
            }
            if(option === 'EXIT') alert('Game Exit!');
            break;
        case 'intro':
            currentScreen = 'camp_entrance';
            setMenu(['Go to Bonfire', 'Enter Command Tent']);
            break;
        case 'camp_entrance':
            if(option === 'Go to Bonfire') currentScreen = 'bonfire';
            if(option === 'Enter Command Tent') currentScreen = 'command_tent';
            setMenu([]);
            break;
        case 'bonfire':
            currentScreen = 'trail';
            setMenu([]);
            break;
        case 'command_tent':
            currentScreen = 'trail';
            setMenu([]);
            break;
        case 'trail':
            currentScreen = 'escape_run';
            setMenu([]);
            break;
        case 'escape_run':
            currentScreen = 'ending';
            setMenu([]);
            break;
        case 'ending':
            currentScreen = 'title';
            setMenu(['START','EXIT']);
            break;
    }
}

async function init() {
    await loadAllScreens();
    currentScreen = 'title';
    setMenu(['START','EXIT']);
    showScreen();
    window.addEventListener('keydown', handleInput);
}

init();
