const terminalContainer = document.getElementById('game-screen');

let commandHistory = [];
let historyIndex = 0;

const professorResponses = {
    help: "Available commands: help, clear, start, status",
    clear: "Screen cleared. Don't forget to observe everything.",
    start: "Mission started. Stay sharp!",
    status: "All systems nominal. You are learning well."
};

function appendLine(text) {
    terminalContainer.textContent += '\n' + text;
    terminalContainer.scrollTop = terminalContainer.scrollHeight;
}

function executeCommand(command) {
    commandHistory.push(command);
    historyIndex = commandHistory.length;

    const cmd = command.trim().toLowerCase();

    if (professorResponses[cmd]) {
        appendLine("> " + command);
        appendLine(professorResponses[cmd]);
    } else {
        appendLine("> " + command);
        appendLine("Unknown command. Try something else.");
    }
}

function setupInput() {
    const inputLine = document.createElement('div');
    inputLine.setAttribute('id', 'terminal-input');
    inputLine.textContent = "> ";
    terminalContainer.appendChild(inputLine);

    let currentCommand = "";

    window.addEventListener('keydown', (e) => {
        if (e.key.length === 1) {
            currentCommand += e.key;
            inputLine.textContent = "> " + currentCommand;
        }
        if (e.key === 'Backspace') {
            currentCommand = currentCommand.slice(0, -1);
            inputLine.textContent = "> " + currentCommand;
        }
        if (e.key === 'Enter') {
            executeCommand(currentCommand);
            currentCommand = "";
            inputLine.textContent = "> ";
        }
        if (e.key === 'ArrowUp') {
            if (historyIndex > 0) {
                historyIndex--;
                currentCommand = commandHistory[historyIndex];
                inputLine.textContent = "> " + currentCommand;
            }
        }
        if (e.key === 'ArrowDown') {
            if (historyIndex < commandHistory.length - 1) {
                historyIndex++;
                currentCommand = commandHistory[historyIndex];
                inputLine.textContent = "> " + currentCommand;
            } else {
                historyIndex = commandHistory.length;
                currentCommand = "";
                inputLine.textContent = "> ";
            }
        }
    });
}

setupInput();
