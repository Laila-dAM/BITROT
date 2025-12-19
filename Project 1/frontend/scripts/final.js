let escapeMenuOptions = ['MOVE UP', 'MOVE LEFT', 'MOVE DOWN', 'MOVE RIGHT'];
let escapeMenuIndex = 0;

function startEscapeSequence() {
    showEscapeScreen();
    window.addEventListener('keydown', handleEscapeInput);
}

function showEscapeScreen() {
    const container = document.getElementById('game-screen');
    const lines = screens['escape_sequence'].slice();

    escapeMenuOptions.forEach((option, i) => {
        const index = lines.findIndex(line => line.includes(option));
        if (index !== -1) {
            lines[index] = (i === escapeMenuIndex ? '>' : ' ') + lines[index].slice(1);
        }
    });

    container.textContent = lines.join('\n');
}

function handleEscapeInput(e) {
    if (e.key === 'w' || e.key === 'ArrowUp') {
        escapeMenuIndex = (escapeMenuIndex - 1 + escapeMenuOptions.length) % escapeMenuOptions.length;
        showEscapeScreen();
    }
    if (e.key === 's' || e.key === 'ArrowDown') {
        escapeMenuIndex = (escapeMenuIndex + 1) % escapeMenuOptions.length;
        showEscapeScreen();
    }
    if (e.key === 'Enter') {
        handleEscapeAction(escapeMenuOptions[escapeMenuIndex]);
    }
}

function handleEscapeAction(action) {
    let message = '';
    switch(action) {
        case 'MOVE UP':
            message = 'You advance cautiously.';
            break;
        case 'MOVE LEFT':
            message = 'You dodge left.';
            break;
        case 'MOVE DOWN':
            message = 'You step back.';
            break;
        case 'MOVE RIGHT':
            message = 'You swerve right.';
            break;
    }
    alert(message);
    if (action === 'MOVE UP') {
        showEnding();
    }
}

function showEnding() {
    const container = document.getElementById('game-screen');
    container.textContent = screens['ending_city'].join('\n');
}
