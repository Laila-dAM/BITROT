const GameState = {
    currentScene: "forest_start",
    playerPosition: { x: 0, y: 0 },
    inventory: [],
};

function saveProgress() {
    localStorage.setItem("gameState", JSON.stringify(GameState));
}

function loadProgress() {
    const saved = localStorage.getItem("gameState");
    if(saved) {
        Object.assign(GameState, JSON.parse(saved));
    }
}
