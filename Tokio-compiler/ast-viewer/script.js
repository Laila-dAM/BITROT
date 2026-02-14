async function loadAST() {
    const response = await fetch('data/sample_ast.json');
    const ast = await response.json();
    const container = document.getElementById('ast-container');
    container.innerHTML = '';
    container.appendChild(renderNode(ast));
}

function renderNode(node) {
    const nodeElement = document.createElement('div');
    nodeElement.classList.add('node');

    const label = document.createElement('div');
    label.classList.add('label');
    label.textContent = node.type + (node.name ? `: ${node.name}` : '');
    nodeElement.appendChild(label);

    if (node.children && node.children.length > 0) {
        const childrenContainer = document.createElement('div');
        childrenContainer.classList.add('children');
        node.children.forEach(child => {
            childrenContainer.appendChild(renderNode(child));
        });
        nodeElement.appendChild(childrenContainer);
    }

    return nodeElement;
}

window.addEventListener('DOMContentLoaded', () => {
    loadAST();
});
