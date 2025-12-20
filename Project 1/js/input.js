import { state, movePlayer } from "./state.js"
import { loadScene } from "./sceneManager.js"

export function initInput() {
  document.addEventListener("keydown", handleKey)
}

function handleKey(e) {
  let x = state.player.x
  let y = state.player.y

  if (e.key === "w") y -= 1
  if (e.key === "s") y += 1
  if (e.key === "a") x -= 1
  if (e.key === "d") x += 1

  movePlayer(x, y)
}
