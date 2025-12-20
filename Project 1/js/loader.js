import { renderText } from "./renderer.js"

export async function loadText(path) {
  const response = await fetch(path)
  const content = await response.text()
  renderText(content)
}
