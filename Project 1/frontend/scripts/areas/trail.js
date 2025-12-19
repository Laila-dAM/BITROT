let trailOptions = ['PATH A : DARK FOREST', 'PATH B : SUNNY GLADE', 'PATH C : MYSTIC STREAM'];
let trailIndex = 0;

function startTrail() {
    showTrailScreen();
    window.addEventListener('keydown', handleTrailInput);
}

function showTrailScreen() {
    const container = document.getElementById('game-screen');
    const lines = screens['trail'].slice();

    trailOptions.forEach((option, i) => {
        const index = lines.findIndex(line => line.includes(option));
        if (index !== -1) {
            lines[index] = (i === trailIndex ? '>' : ' ') + lines[index].slice(1);
        }
    });

    container.textContent = lines.join('\n');
}

function handleTrailInput(e) {
    if (e.key === 'w' || e.key === 'ArrowUp') {
        trailIndex = (trailIndex - 1 + trailOptions.length) % trailOptions.length;
        showTrailScreen();
    }
    if (e.key === 's' || e.key === 'ArrowDown') {
        trailIndex = (trailIndex + 1) % trailOptions.length;
        showTrailScreen();
    }
    if (e.key === 'Enter') {
        const selected = trailOptions[trailIndex];
        handleTrailChoice(selected);
    }
}

function handleTrailChoice(choice) {
    let message = '';
    let xp = 0;
    switch(choice) {
        case 'PATH A : DARK FOREST':
            message = '🌲 You got lost in the dark forest. Try again.';
            xp = 0;
            break;
        case 'PATH B : SUNNY GLADE':
            message = '🌞 You walk safely through the sunny glade. Progress forward.';
            xp = 10;
            break;
        case 'PATH C : MYSTIC STREAM':
            message = '💧 The mystic stream confuses you. Back to start.';
            xp = 0;
            break;
    }
    alert(message);
    completeChallenge('trail', xp);
    window.removeEventListener('keydown', handleTrailInput);
    trailIndex = 0;
}
