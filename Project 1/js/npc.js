import { openDialogue } from "./dialogue.js"
import { state } from "./state.js"

const npcs = {
  professor: {
    x: 10,
    y: 6
  }
}

export function getNPCAt(x, y) {
  return Object.values(npcs).find(n => n.x === x && n.y === y)
}

export function interactWithNPC(npc) {
  if (!npc) return

  let path = "assets/ascii/dialogues/professor_low_xp.json"

  if (state.flags.chose_learn) {
    path = "assets/ascii/dialogues/professor_learning.json"
  }

  if (state.flags.chose_escape) {
    path = "assets/ascii/dialogues/professor_escape.json"
  }

  openDialogue(path)
}
