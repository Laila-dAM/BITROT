let gameState = {
    currentArea: 'camp_entrance',
    xp: 0,
    level: 1,
    completedChallenges: []
};

let hubOptions = ['GO TO BONFIRE', 'GO TO TRAIL', 'GO TO ESCAPE RUN', 'VIEW STATUS'];
let hubIndex = 0;

function startHub() {
    hubIndex = 0;
    showHubScreen();
    window.addEventListener('keydown', handleHubInput);
}

function showHubScreen() {
    const container = document.getElementById('game-screen');
    const lines = screens['camp_entrance'].slice();
    hubOptions.forEach((option, i) => {
        const index = lines.findIndex(line => line.includes(option));
        if (index !== -1) lines[index] = (i === hubIndex ? '>' : ' ') + lines[index].slice(1);
    });

    lines.push(`XP: ${gameState.xp} | Level: ${gameState.level}`);
    container.textContent = lines.join('\n');
}

function handleHubInput(e) {
    if (e.key === 'w' || e.key === 'ArrowUp') hubIndex = (hubIndex - 1 + hubOptions.length) % hubOptions.length;
    if (e.key === 's' || e.key === 'ArrowDown') hubIndex = (hubIndex + 1) % hubOptions.length;
    if (e.key === 'Enter') executeHubAction(hubOptions[hubIndex]);
    showHubScreen();
}

function executeHubAction(option) {
    switch(option) {
        case 'GO TO BONFIRE':
            gameState.currentArea = 'bonfire';
            startBonfire();
            break;
        case 'GO TO TRAIL':
            gameState.currentArea = 'trail';
            startTrail();
            break;
        case 'GO TO ESCAPE RUN':
            gameState.currentArea = 'escape_run';
            startEscapeRun();
            break;
        case 'VIEW STATUS':
            alert(`XP: ${gameState.xp}\nLevel: ${gameState.level}\nCompleted: ${gameState.completedChallenges.join(', ')}`);
            break;
    }
}

function completeChallenge(name, xpReward = 10) {
    if (!gameState.completedChallenges.includes(name)) {
        gameState.completedChallenges.push(name);
        gameState.xp += xpReward;
        if (gameState.xp >= gameState.level * 50) {
            gameState.level += 1;
            alert(`🎉 Level up! You are now level ${gameState.level}`);
        }
    }
    gameState.currentArea = 'camp_entrance';
    startHub();
}
