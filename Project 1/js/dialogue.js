import { renderText } from "./renderer.js"

let active = false
let content = ""

export async function openDialogue(path) {
  active = true
  const res = await fetch(path)
  content = await res.text()
  draw()
}

export function isDialogueActive() {
  return active
}

export function handleDialogueInput(key) {
  if (!active) return
  if (key === "Enter") active = false
}

function draw() {
  renderText(content)
}
