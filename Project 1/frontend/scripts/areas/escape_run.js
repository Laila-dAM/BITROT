let escapeMenuOptions = ['MOVE UP', 'MOVE LEFT', 'MOVE DOWN', 'MOVE RIGHT'];
let escapeMenuIndex = 0;

function startEscapeRun() {
    escapeMenuIndex = 0;
    showEscapeScreen();
    window.addEventListener('keydown', handleEscapeInput);
}

function showEscapeScreen() {
    const container = document.getElementById('game-screen');
    const lines = screens['escape_run'].slice();
    escapeMenuOptions.forEach((option, i) => {
        const index = lines.findIndex(line => line.includes(option));
        if (index !== -1) lines[index] = (i === escapeMenuIndex ? '>' : ' ') + lines[index].slice(1);
    });
    container.textContent = lines.join('\n');
}

function handleEscapeInput(e) {
    if (e.key === 'w' || e.key === 'ArrowUp') escapeMenuIndex = (escapeMenuIndex - 1 + escapeMenuOptions.length) % escapeMenuOptions.length;
    if (e.key === 's' || e.key === 'ArrowDown') escapeMenuIndex = (escapeMenuIndex + 1) % escapeMenuOptions.length;
    if (e.key === 'Enter') handleEscapeAction(escapeMenuOptions[escapeMenuIndex]);
    showEscapeScreen();
}

function handleEscapeAction(action) {
    let message = '';
    switch(action) {
        case 'MOVE UP': message = 'You move forward cautiously.'; break;
        case 'MOVE LEFT': message = 'You shift left, scanning the area.'; break;
        case 'MOVE DOWN': message = 'You move backward to reassess.'; break;
        case 'MOVE RIGHT': message = 'You step right, careful not to make noise.'; break;
    }
    alert(message);
}
