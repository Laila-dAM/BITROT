import { renderText } from "./renderer.js"
import { checkAnswer, clearChallenge, getReward, applyUnlock } from "./challenges.js"
import { addXP } from "./state.js"

let buffer = ""
let active = false
let message = ""

export function openTerminal(prompt = "") {
  active = true
  buffer = ""
  message = prompt
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
    if (checkAnswer(buffer)) {
      const xp = getReward()
      addXP(xp)
      applyUnlock()
      message = `Success +${xp} XP`
      clearChallenge()
      setTimeout(() => closeTerminal(), 1000)
    } else {
      message = "Error"
      buffer = ""
    }
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

${message}

> ${buffer}`
  )
}
