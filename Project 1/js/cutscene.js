import { renderText } from "./renderer.js"

let active = false
let content = ""

export async function playCutscene(path) {
  active = true
  const response = await fetch(path)
  content = await response.text()
  draw()
}

export function isCutsceneActive() {
  return active
}

export function handleCutsceneInput(key) {
  if (!active) return
  if (key === "Enter") active = false
}

function draw() {
  renderText(content)
}
