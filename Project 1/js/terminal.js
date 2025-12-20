import { renderText } from "./renderer.js"

let buffer = ""
let active = false

export function openTerminal() {
  active = true
  buffer = ""
  draw()
}

export function closeTerminal() {
  active = false
}

export function isTerminalActive() {
  return active
}

export function handleTerminalInput(key) {
  if (!active) return

  if (key === "Enter") {
    buffer += "\n> command received"
  } else if (key === "Backspace") {
    buffer = buffer.slice(0, -1)
  } else if (key.length === 1) {
    buffer += key
  }

  draw()
}

function draw() {
  renderText(
`=== TERMINAL ===

> ${buffer}`
  )
}
