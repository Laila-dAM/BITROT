import { setMap } from "./mapRenderer.js"

export async function loadText(path) {
  const response = await fetch(path)
  const content = await response.text()
  setMap(content)
}
