import { state, movePlayer } from "./state.js"
import { draw, isBlocked, getTile } from "./mapRenderer.js"
import { handleTrigger } from "./triggers.js"
import { handleTerminalInput, isTerminalActive } from "./terminal.js"
import { isCutsceneActive, handleCutsceneInput } from "./cutscene.js"
import { isDialogueActive, handleDialogueInput } from "./dialogue.js"
import { getNPCAt, interactWithNPC } from "./npc.js"

export function initInput() {
  document.addEventListener("keydown", handleKey)
}

function handleKey(e) {
  if (isCutsceneActive()) {
    handleCutsceneInput(e.key)
    draw()
    return
  }

  if (isDialogueActive()) {
    handleDialogueInput(e.key)
    draw()
    return
  }

  if (isTerminalActive()) {
    handleTerminalInput(e.key)
    return
  }

  if (e.key === "e") {
    const npc = getNPCAt(state.player.x, state.player.y - 1)
    interactWithNPC(npc)
    return
  }

  let x = state.player.x
  let y = state.player.y

  if (e.key === "w") y -= 1
  if (e.key === "s") y += 1
  if (e.key === "a") x -= 1
  if (e.key === "d") x += 1

  if (isBlocked(x, y)) return

  movePlayer(x, y)

  const tile = getTile(x, y)
  if (tile) handleTrigger(tile)

  draw()
}
