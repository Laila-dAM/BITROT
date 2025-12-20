import { renderStatus, renderXPBar } from "./uiRenderer.js"

const screen = document.getElementById("screen")

export function renderText(content) {
  screen.textContent =
`${renderStatus()}
${renderXPBar()}

${content}`
}
