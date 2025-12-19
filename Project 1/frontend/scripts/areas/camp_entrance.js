function campEntranceArea() {
    const messages = [
        "You arrive at the camp.",
        "The area is calm, but something feels off.",
        "You can choose your next action carefully."
    ];

    let step = 0;

    function showMessage() {
        if (step < messages.length) {
            alert(messages[step]);
            step++;
        } else {
            alert("Ready to explore or check your inventory.");
        }
    }

    showMessage();
}

if (!window.areas) window.areas = {};
window.areas['camp_entrance'] = campEntranceArea;
