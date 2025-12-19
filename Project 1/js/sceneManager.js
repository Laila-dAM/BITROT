async function loadScene(sceneName) {
    const response = await fetch(`scenes/${sceneName}.txt`);
    const text = await response.text();
    document.getElementById("ascii-scene").textContent = text;
    GameState.currentScene = sceneName;
}

function nextScene(sceneName) {
    loadScene(sceneName);
    saveProgress();
}
