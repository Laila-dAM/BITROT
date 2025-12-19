
const screens = {};  
async function loadScreen(name) {
    const response = await fetch(`assets/ascii/screens/${name}.txt`);
    const text = await response.text();
    screens[name] = text.split('\n');
}

async function loadAllScreens() {
    const screenNames = [
        'title','intro','game_over','camp_entrance','bonfire',
        'command_tent','escape_run','trail','ending'
    ];
    for (let name of screenNames) await loadScreen(name);
}

function showScreen(name, options = [], index = 0) {
    const container = document.getElementById('game-screen');
    const lines = screens[name].slice();
    options.forEach((option, i) => {
        const lineIndex = lines.findIndex(line => line.includes(option));
        if (lineIndex !== -1) lines[lineIndex] = (i === index ? '>' : ' ') + lines[lineIndex].slice(1);
    });
    container.textContent = lines.join('\n');
}
