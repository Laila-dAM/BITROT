let commandHistory = [];
let maxHistory = 10;

function startCommandTent() {
    showCommandTentScreen();
    window.addEventListener('keydown', handleCommandInput);
}

function showCommandTentScreen() {
    const container = document.getElementById('game-screen');
    const lines = screens['command_tent'].slice();
    if (commandHistory.length > 0) {
        lines.push('');
        commandHistory.slice(-maxHistory).forEach(cmd => {
            lines.push(cmd);
        });
    }
    container.textContent = lines.join('\n');
}

function handleCommandInput(e) {
    if (e.key === 'Enter') {
        const input = prompt('Type command:').trim().toLowerCase();
        if (!input) return;

        let response = '';
        switch(input) {
            case 'help':
                response = 'Commands: help, clear, start, status';
                break;
            case 'clear':
                commandHistory = [];
                showCommandTentScreen();
                return;
            case 'start':
                response = 'Mission started. Try not to break everything.';
                break;
            case 'status':
                response = 'All systems nominal. Or are they?';
                break;
            default:
                response = `Unknown command: ${input}`;
        }

        commandHistory.push(`> ${input}`);
        commandHistory.push(response);
        if (commandHistory.length > maxHistory) {
            commandHistory = commandHistory.slice(-maxHistory);
        }
        showCommandTentScreen();
    }
}
