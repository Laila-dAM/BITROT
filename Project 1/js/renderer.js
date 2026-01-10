import { renderStatus, renderXPBar } from "./uiRenderer.js"

const screen = document.getElementById("screen")
let timer

export function renderText(content, typewriter = true) {
  clearInterval(timer)

  const fullText =
`${renderStatus()}
${renderXPBar()}

${content}`

  screen.textContent = ""

  if (!typewriter) {
    screen.textContent = fullText
    return
  }

  let i = 0
  timer = setInterval(() => {
    screen.textContent += fullText[i] || ""
    i++
    if (i >= fullText.length) clearInterval(timer)
  }, 10)
}
