let bonfireSteps = ['STEP 1 : PICK UP WOOD', 'STEP 2 : STACK WOOD', 'STEP 3 : LIGHT FIRE'];
let bonfireIndex = 0;

function startBonfire() {
    showBonfireScreen();
    window.addEventListener('keydown', handleBonfireInput);
}

function showBonfireScreen() {
    const container = document.getElementById('game-screen');
    const lines = screens['bonfire'].slice();

    bonfireSteps.forEach((step, i) => {
        const index = lines.findIndex(line => line.includes(step));
        if (index !== -1) {
            lines[index] = (i === bonfireIndex ? '>' : ' ') + lines[index].slice(1);
        }
    });

    container.textContent = lines.join('\n');
}

function handleBonfireInput(e) {
    if (e.key === 'w' || e.key === 'ArrowUp') {
        bonfireIndex = (bonfireIndex - 1 + bonfireSteps.length) % bonfireSteps.length;
        showBonfireScreen();
    }
    if (e.key === 's' || e.key === 'ArrowDown') {
        bonfireIndex = (bonfireIndex + 1) % bonfireSteps.length;
        showBonfireScreen();
    }
    if (e.key === 'Enter') {
        const selected = bonfireSteps[bonfireIndex];
        handleBonfireStep(selected);
    }
}

function handleBonfireStep(step) {
    const correctStep = bonfireSteps[0];
    if (step === correctStep) {
        bonfireSteps.shift();
        if (bonfireSteps.length === 0) {
            alert('🔥 The fire ignites! Well done.');
            completeChallenge('bonfire', 15);
            window.removeEventListener('keydown', handleBonfireInput);
            bonfireSteps = ['STEP 1 : PICK UP WOOD', 'STEP 2 : STACK WOOD', 'STEP 3 : LIGHT FIRE'];
        } else {
            alert(`✅ ${step} completed. Next step.`);
        }
        showBonfireScreen();
    } else {
        alert('❌ Wrong order! Try again.');
        bonfireSteps = ['STEP 1 : PICK UP WOOD', 'STEP 2 : STACK WOOD', 'STEP 3 : LIGHT FIRE'];
        bonfireIndex = 0;
        showBonfireScreen();
    }
}
